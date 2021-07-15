
cc_library(
	name = "detdb",
	srcs = [
	     "coco.cxx"
	],
	hdrs = [
	     "base.hxx",
	     "coco.hxx",
	     "utils.hxx",
	     "bbox.hxx"
	],
	deps = ["@boost//:filesystem", "@boost//:system",
	"@com_github_open_source_parsers_jsoncpp//:jsoncpp"],
	visibility = ["//:__pkg__"],
	linkstatic=0
)



cc_binary(
	name = "main",
	srcs = [
	     "main.cxx"
	],
	deps = [
	     ":detdb",
	     "@com_github_google_glog//:glog",
	     
	]
)