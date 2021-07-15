cc_library(
	name = "boost-headers",
	hdrs = glob(["include/**"]),
	visibility = ["//visibility:public"],
	includes = ["include"],
)

cc_library(
	name = "filesystem",
	srcs = ["lib/libboost_filesystem.so"],
	visibility = ["//visibility:public"]
)

cc_library(
	name = "system",
	srcs = ["lib/libboost_system.so"],
	visibility = ["//visibility:public"]
)

