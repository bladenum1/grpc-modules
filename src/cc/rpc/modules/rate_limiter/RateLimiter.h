#ifndef RATELIMITER_H
#define RATELIMITER_H

#include "src/cc/rpc/modules/interface/Interface.h"

namespace RPC::Modules {
/// Error codes associated with the RateLimiter module.
class RateLimiterError : public InterfaceError {
public:
  enum {
    RateLimited = InterfaceError::Last,
    Last,
  };
};

/// RateLimiter module.
/// Used for rate limiting specified grpc calls.
class RateLimiter : public Interface {
  /// Handler to rate limit grpc calls.
  ///
  /// @param func The function to run if not rate limited.
  ///
  /// @returns A grpc status associated with the call.
  grpc::Status handler(
      std::function<Expected<grpc::Status, InterfaceError>(
          grpc::ServerContext *context, const google::protobuf::Any *request,
          google::protobuf::Any *response)>
          func) noexcept override;
};
} // namespace RPC::Modules

#endif
