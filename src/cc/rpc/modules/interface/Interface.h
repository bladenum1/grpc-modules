#ifndef INTERFACE_H
#define INTERFACE_H

#include <google/protobuf/any.pb.h>
#include <grpcpp/grpcpp.h>

namespace RPC::Modules {

/// Template class to return either a value or error.
template <typename ReturnT, typename ErrorT> class Expected {
public:
  ReturnT value;
  ErrorT error;
};

/// Class to be extended derived classes with subsequent error codes.
class InterfaceError {
public:
  enum {
    Internal = 1,
    Last = 2,
  };
};

/// Interface for all grpc modules to be derived from.
class Interface {
public:
  /// Handler method to run the provided Expected function.
  ///
  /// @param func The function associated with a grpc call.
  ///
  /// @returns A grpc status for the associated call.
  virtual grpc::Status handler(
      std::function<Expected<grpc::Status, InterfaceError>(
          grpc::ServerContext *context, const google::protobuf::Any *request,
          google::protobuf::Any *response)>) noexcept = 0;
};
} // namespace RPC::Modules

#endif
