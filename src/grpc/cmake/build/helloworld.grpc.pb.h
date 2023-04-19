// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: helloworld.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_helloworld_2eproto__INCLUDED
#define GRPC_helloworld_2eproto__INCLUDED

#include "helloworld.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace postgresGRPC {

// The greeting service definition.
class Greeter final {
 public:
  static constexpr char const* service_full_name() {
    return "postgresGRPC.Greeter";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends a greeting
    virtual ::grpc::Status SayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::postgresGRPC::HelloReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>> AsyncSayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>>(AsyncSayHelloRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>> PrepareAsyncSayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>>(PrepareAsyncSayHelloRaw(context, request, cq));
    }
    virtual ::grpc::Status sendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::postgresGRPC::HelloReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>> AsyncsendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>>(AsyncsendPlanRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>> PrepareAsyncsendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>>(PrepareAsyncsendPlanRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Sends a greeting
      virtual void SayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest* request, ::postgresGRPC::HelloReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest* request, ::postgresGRPC::HelloReply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void sendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC* request, ::postgresGRPC::HelloReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void sendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC* request, ::postgresGRPC::HelloReply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>* PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>* AsyncsendPlanRaw(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::postgresGRPC::HelloReply>* PrepareAsyncsendPlanRaw(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status SayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::postgresGRPC::HelloReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>> AsyncSayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>>(AsyncSayHelloRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>> PrepareAsyncSayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>>(PrepareAsyncSayHelloRaw(context, request, cq));
    }
    ::grpc::Status sendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::postgresGRPC::HelloReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>> AsyncsendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>>(AsyncsendPlanRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>> PrepareAsyncsendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>>(PrepareAsyncsendPlanRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void SayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest* request, ::postgresGRPC::HelloReply* response, std::function<void(::grpc::Status)>) override;
      void SayHello(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest* request, ::postgresGRPC::HelloReply* response, ::grpc::ClientUnaryReactor* reactor) override;
      void sendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC* request, ::postgresGRPC::HelloReply* response, std::function<void(::grpc::Status)>) override;
      void sendPlan(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC* request, ::postgresGRPC::HelloReply* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>* PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::postgresGRPC::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>* AsyncsendPlanRaw(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::postgresGRPC::HelloReply>* PrepareAsyncsendPlanRaw(::grpc::ClientContext* context, const ::postgresGRPC::PlannedStmtRPC& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SayHello_;
    const ::grpc::internal::RpcMethod rpcmethod_sendPlan_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends a greeting
    virtual ::grpc::Status SayHello(::grpc::ServerContext* context, const ::postgresGRPC::HelloRequest* request, ::postgresGRPC::HelloReply* response);
    virtual ::grpc::Status sendPlan(::grpc::ServerContext* context, const ::postgresGRPC::PlannedStmtRPC* request, ::postgresGRPC::HelloReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SayHello() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayHello(::grpc::ServerContext* context, ::postgresGRPC::HelloRequest* request, ::grpc::ServerAsyncResponseWriter< ::postgresGRPC::HelloReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_sendPlan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_sendPlan() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_sendPlan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendPlan(::grpc::ServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsendPlan(::grpc::ServerContext* context, ::postgresGRPC::PlannedStmtRPC* request, ::grpc::ServerAsyncResponseWriter< ::postgresGRPC::HelloReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SayHello<WithAsyncMethod_sendPlan<Service > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_SayHello() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::postgresGRPC::HelloRequest, ::postgresGRPC::HelloReply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::postgresGRPC::HelloRequest* request, ::postgresGRPC::HelloReply* response) { return this->SayHello(context, request, response); }));}
    void SetMessageAllocatorFor_SayHello(
        ::grpc::MessageAllocator< ::postgresGRPC::HelloRequest, ::postgresGRPC::HelloReply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::postgresGRPC::HelloRequest, ::postgresGRPC::HelloReply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SayHello(
      ::grpc::CallbackServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_sendPlan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_sendPlan() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::postgresGRPC::PlannedStmtRPC, ::postgresGRPC::HelloReply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::postgresGRPC::PlannedStmtRPC* request, ::postgresGRPC::HelloReply* response) { return this->sendPlan(context, request, response); }));}
    void SetMessageAllocatorFor_sendPlan(
        ::grpc::MessageAllocator< ::postgresGRPC::PlannedStmtRPC, ::postgresGRPC::HelloReply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::postgresGRPC::PlannedStmtRPC, ::postgresGRPC::HelloReply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_sendPlan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendPlan(::grpc::ServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* sendPlan(
      ::grpc::CallbackServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_SayHello<WithCallbackMethod_sendPlan<Service > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SayHello() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_sendPlan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_sendPlan() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_sendPlan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendPlan(::grpc::ServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SayHello() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayHello(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_sendPlan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_sendPlan() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_sendPlan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendPlan(::grpc::ServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsendPlan(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_SayHello() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SayHello(context, request, response); }));
    }
    ~WithRawCallbackMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* SayHello(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_sendPlan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_sendPlan() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->sendPlan(context, request, response); }));
    }
    ~WithRawCallbackMethod_sendPlan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendPlan(::grpc::ServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* sendPlan(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SayHello() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::postgresGRPC::HelloRequest, ::postgresGRPC::HelloReply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::postgresGRPC::HelloRequest, ::postgresGRPC::HelloReply>* streamer) {
                       return this->StreamedSayHello(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* /*context*/, const ::postgresGRPC::HelloRequest* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSayHello(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::postgresGRPC::HelloRequest,::postgresGRPC::HelloReply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_sendPlan : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_sendPlan() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::postgresGRPC::PlannedStmtRPC, ::postgresGRPC::HelloReply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::postgresGRPC::PlannedStmtRPC, ::postgresGRPC::HelloReply>* streamer) {
                       return this->StreamedsendPlan(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_sendPlan() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status sendPlan(::grpc::ServerContext* /*context*/, const ::postgresGRPC::PlannedStmtRPC* /*request*/, ::postgresGRPC::HelloReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedsendPlan(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::postgresGRPC::PlannedStmtRPC,::postgresGRPC::HelloReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SayHello<WithStreamedUnaryMethod_sendPlan<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SayHello<WithStreamedUnaryMethod_sendPlan<Service > > StreamedService;
};

}  // namespace postgresGRPC


#endif  // GRPC_helloworld_2eproto__INCLUDED
