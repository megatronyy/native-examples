# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library

# gcc -I /usr/lib/jvm/java-8-openjdk-amd64/include/ -I /usr/lib/jvm/java-8-openjdk-amd64/include/linux/ Stdafx.h jvmti_evt_ex.h jvmti_evt_ex.cpp -fPIC -shared -o libexten.so

cc_library(
    name = "jvmti_evt_ex",
    srcs = ["jvmti_evt_ex.cpp"],
    hdrs = ["Stdafx.h", "jvmti_evt_ex.h", "/usr/lib/jvm/java-8-openjdk-amd64/include/jvmti.h"],
)