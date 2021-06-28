# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library

# 如何在bazel构建期间添加外部头文件（https://www.it1352.com/1967650.html）

cc_library(
    name = "openjdk",
    hdrs = glob(["include/*.h", "include/linux/*.h"]),
    visibility = ["//visibility:public"],
)