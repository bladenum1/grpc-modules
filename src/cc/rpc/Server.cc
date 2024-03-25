#include "src/cc/rpc/Server.h"

namespace RPC {
grpc::Status Server::Get(grpc::ServerContext *context,
                         const Basic::GetRequest *request,
                         Basic::GetResponse *response) {
  return grpc::Status::OK;
}
} // namespace RPC
