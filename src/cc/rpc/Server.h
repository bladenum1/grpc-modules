#ifndef SERVER_H
#define SERVER_H

#include "src/cc/rpc/modules/rate_limiter/RateLimiter.h"
#include "src/proto/service.grpc.pb.h"

namespace RPC {
class Server : public Basic::Server::Service {
public:
  /// Get protobuf method.
  ///
  /// @param context The server context associated with the call.
  /// @param request The GetRequest associated with the call.
  /// @param response The GetResponse to be populated.
  ///
  /// @returns A grpc status for the associated call.
  grpc::Status Get(grpc::ServerContext *context,
                   const Basic::GetRequest *request,
                   Basic::GetResponse *response);

private:
  /// Rate limiter module to enforce limits.
  Modules::RateLimiter rate_limiter{};
};
} // namespace RPC

#endif
