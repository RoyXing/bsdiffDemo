#include <jni.h>
#include <string>

extern "C" {
extern int p_main(int args, const char *argv[]);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xingzy_BsPathcher_bsPatch(JNIEnv *env, jclass type, jstring oldApk_, jstring patch_,
                                   jstring output_) {
    const char *oldApk = env->GetStringUTFChars(oldApk_, 0);
    const char *patch = env->GetStringUTFChars(patch_, 0);
    const char *output = env->GetStringUTFChars(output_, 0);


    const char *argv[] = {"", oldApk, output, patch};
    p_main(4, argv);

    env->ReleaseStringUTFChars(oldApk_, oldApk);
    env->ReleaseStringUTFChars(patch_, patch);
    env->ReleaseStringUTFChars(output_, output);
}