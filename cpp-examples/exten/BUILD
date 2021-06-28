# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library

# gcc -I /usr/lib/jvm/java-8-openjdk-amd64/include/ -I /usr/lib/jvm/java-8-openjdk-amd64/include/linux/ Stdafx.h jvmti_evt_ex.h jvmti_evt_ex.cpp -fPIC -shared -o libexten.so

# ln -s /usr/lib/jvm/java-8-openjdk-amd64/include /home/wenbin/examples/native-examples/cpp-examples/third_party/openjdk

# 如何在bazel构建期间添加外部头文件（https://www.it1352.com/1967650.html）

cc_library(
    name = "jvmti_evt_ex",
    srcs = ["jvmti_evt_ex.cpp"],
    hdrs = ["Stdafx.h", "jvmti_evt_ex.h"],
    visibility = ["//visibility:public"],
    copts = ["-Ithird_party/openjdk/include", "-Ithird_party/openjdk/include/linux"],
    deps = [
        "//third_party/openjdk",
    ],
)