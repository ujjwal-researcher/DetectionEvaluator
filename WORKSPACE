new_local_repository(
	name = "boost",
	path = "/opt/boost/1.58.0",
	build_file = "third_party/boost.BUILD"
)



load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = ["https://github.com/gflags/gflags/archive/v2.2.2.tar.gz"],
)

http_archive(
    name = "com_github_google_glog",
    sha256 = "21bc744fb7f2fa701ee8db339ded7dce4f975d0d55837a97be7d46e8382dea5a",
    strip_prefix = "glog-0.5.0",
    urls = ["https://github.com/google/glog/archive/v0.5.0.zip"],
)


load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "org_cloudabi_bazel_third_party",
    commit = "91ca2167219c612a89334fa09ddf15fbdc5d0592",
    remote = "https://github.com/NuxiNL/bazel-third-party.git",
)

load("@org_cloudabi_bazel_third_party//:third_party.bzl", "third_party_repositories")

third_party_repositories()