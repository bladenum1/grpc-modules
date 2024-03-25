#include "src/cc/rpc/modules/rate_limiter/RateLimiter.h"

namespace RPC::Modules {
grpc::Status RateLimiter::handler(
    std::function<Expected<grpc::Status, InterfaceError>(
        grpc::ServerContext *context, const google::protobuf::Any *request,
        google::protobuf::Any *response)>
        func) noexcept {
  return grpc::Status::OK;
}
} // namespace RPC::Modules
