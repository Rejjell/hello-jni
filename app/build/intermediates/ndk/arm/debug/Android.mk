LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := hello-jni
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_LDLIBS := \
	-lsqlite \

LOCAL_SRC_FILES := \
	F:\work\hello-jni\app\src\main\jni\Android.mk \
	F:\work\hello-jni\app\src\main\jni\Application.mk \
	F:\work\hello-jni\app\src\main\jni\empty.c \
	F:\work\hello-jni\app\src\main\jni\hello-jni.c \

LOCAL_C_INCLUDES += F:\work\hello-jni\app\src\main\jni
LOCAL_C_INCLUDES += F:\work\hello-jni\app\src\arm\jni
LOCAL_C_INCLUDES += F:\work\hello-jni\app\src\debug\jni
LOCAL_C_INCLUDES += F:\work\hello-jni\app\src\armDebug\jni

include $(BUILD_SHARED_LIBRARY)
