load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "service_proto",
    srcs = ["service.proto"],
)

cc_proto_library(
    name = "service_cc_proto",
    deps = [":service_proto"],
    visibility = ["//visibility:public"],
)

cc_grpc_library(
    name = "service_cc_grpc",
    srcs = [":service_proto"],
    deps = [":service_cc_proto"],
    grpc_only = True,
    visibility = ["//visibility:public"],
)

