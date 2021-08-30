#include <jni.h>
#include "student.h"
#include <iostream>
using namespace std;

JNIEXPORT void JNICALL 
Java_student_nativeMethod(JNIEnv *env, jobject obj, jstring name, jstring university, jstring branch)
{
    jclass cls = env->GetObjectClass(obj);
    jfieldID name_ID = env->GetFieldID(cls,"name","Ljava/lang/String;");
    jfieldID university_ID = env->GetFieldID(cls,"university","Ljava/lang/String;");
    jfieldID branch_ID = env->GetFieldID(cls,"branch","Ljava/lang/String;");
    env->SetObjectField(obj,name_ID,name);
    env->SetObjectField(obj,university_ID,university);
    env->SetObjectField(obj,branch_ID,branch);    
}