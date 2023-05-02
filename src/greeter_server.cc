 /*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif



#include "include/nodes/nodes.h"



using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using postgresGRPC::Greeter;
using postgresGRPC::HelloReply;
using postgresGRPC::HelloRequest;
using postgresGRPC::PlannedStmtRPC;


// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    std::cout << "received message: " << request->name() << std::endl;
    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
    
    return Status::OK;
  }

  Status sendPlan(ServerContext* context, const PlannedStmtRPC* request,
                  HelloReply* reply) override {
    std::cout << "received plan message: " << request->plan_width() << std::endl;
    std::string ack("Server ack: plan received");
    char const* liststring = "{PLANNEDSTMT :commandType 1 :queryId 0 :hasReturning false :hasModifyingCTE false :canSetTag true :transientPlan false :dependsOnRole false :parallelModeNeeded false :jitFlags 0 :planTree {SEQSCAN :scan.plan.startup_cost 0 :scan.plan.total_cost 20.625 :scan.plan.plan_rows 4 :scan.plan.plan_width 68 :scan.plan.parallel_aware false :scan.plan.parallel_safe true :scan.plan.async_capable false :scan.plan.plan_node_id 0 :scan.plan.targetlist ({TARGETENTRY :expr {VAR :varno 1 :varattno 1 :vartype 23 :vartypmod -1 :varcollid 0 :varnullingrels (b) :varlevelsup 0 :varnosyn 1 :varattnosyn 1 :location 7} :resno 1 :resname i :ressortgroupref 0 :resorigtbl 16390 :resorigcol 1 :resjunk false} {TARGETENTRY :expr {VAR :varno 1 :varattno 2 :vartype 25 :vartypmod -1 :varcollid 100 :varnullingrels (b) :varlevelsup 0 :varnosyn 1 :varattnosyn 2 :location 7} :resno 2 :resname t :ressortgroupref 0 :resorigtbl 16390 :resorigcol 2 :resjunk false} {TARGETENTRY :expr {VAR :varno 1 :varattno 3 :vartype 17 :vartypmod -1 :varcollid 0 :varnullingrels (b) :varlevelsup 0 :varnosyn 1 :varattnosyn 3 :location 7} :resno 3 :resname b :ressortgroupref 0 :resorigtbl 16390 :resorigcol 3 :resjunk false}) :scan.plan.qual ({OPEXPR :opno 98 :opfuncid 67 :opresulttype 16 :opretset false :opcollid 0 :inputcollid 100 :args ({VAR :varno 1 :varattno 2 :vartype 25 :vartypmod -1 :varcollid 100 :varnullingrels (b) :varlevelsup 0 :varnosyn 1 :varattnosyn 2 :location 26} {CONST :consttype 25 :consttypmod -1 :constcollid 100 :constlen -1 :constbyval false :constisnull false :location 30 :constvalue 5 [ 20 0 0 0 49 ]}) :location 28}) :scan.plan.lefttree <> :scan.plan.righttree <> :scan.plan.initPlan <> :scan.plan.extParam (b) :scan.plan.allParam (b) :scan.scanrelid 1} :partPruneInfos <> :rtable ({RANGETBLENTRY :alias <> :eref {ALIAS :aliasname test1 :colnames ()} :rtekind 0 :relid 16390 :relkind r :rellockmode 1 :tablesample <> :perminfoindex 1 :lateral false :inh false :inFromCl true :securityQuals <>}) :permInfos ({RTEPERMISSIONINFO :relid 16390 :inh true :requiredPerms 2 :checkAsUser 0 :selectedCols (b 8 9 10) :insertedCols (b) :updatedCols (b)}) :resultRelations <> :appendRelations <> :subplans <> :rewindPlanIDs (b) :rowMarks <> :relationOids (o 16390) :invalItems <> :paramExecTypes <> :utilityStmt <> :stmt_location 0 :stmt_len 0}";
    void * plannedStmt = stringToNode(liststring);
    reply->set_message(ack);
    
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}

