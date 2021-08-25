# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "adtexec",
    srcs = ["main.c"],
    deps = [":some_struct"]
)

cc_library(
    name = "some_struct",
    srcs = [
        "some_struct.h",
        "some_struct.c"
    ]
)

cc_binary(
    name = "polym",
    srcs = [
        "polym.c"
    ]
)