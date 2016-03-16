/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include "com_example_hellojni_HelloJni.h"
#include "sqlite/sqlite3.h"
#include <iostream>
#include <fstream>

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    /*int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");*/
    return 0;
}



jstring
Java_com_example_hellojni_HelloJni_stringFromJNI( JNIEnv* env,
                                                  jobject thiz )
{
#if defined(__arm__)
  #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a/NEON (hard-float)"
      #else
        #define ABI "armeabi-v7a/NEON"
      #endif
    #else
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a (hard-float)"
      #else
        #define ABI "armeabi-v7a"
      #endif
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
   #define ABI "x86"
#elif defined(__x86_64__)
   #define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
   #define ABI "mips64"
#elif defined(__mips__)
   #define ABI "mips"
#elif defined(__aarch64__)
   #define ABI "arm64-v8a"
#else
   #define ABI "unknown"
#endif

    sqlite3 *db;
    char *zErrMsg = 0;
    int  rc = 0;
    char *sql;

    //std::ifstream  src ("/data/data/com.android.providers.telephony/databases/telephony.db", std::ios::binary);
    //std::ofstream  dst ("/mnt/sdcard/telephony.db",   std::ios::binary);

    FILE* fp = fopen ("/data/data/com.android.providers.telephony/test_c.txt", "w+");
    //FILE* fp = fopen ("/data/data/com.android.providers.telephony/databases/telephony.db", "r");
    /*
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);*/
    if (fp)
        fclose(fp);
    //dst << src.rdbuf();

    /* Open database */
    sqlite3_initialize();
    //rc = sqlite3_open_v2("/mnt/sdcard/test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    /*rc = sqlite3_open_v2 ("/mnt/sdcard/test.db",
                          &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);*/
    //rc = sqlite3_open_v2("/data/data/com.example.hellojni/db/test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    char* result;
    char info[100];
    strcpy (info, "didn't open, ");
    if( rc ){
        result =(char *) sqlite3_errmsg(db);
        //return (*env)->NewStringUTF(env, strcat(info, result));
        return (env)->NewStringUTF( strcat(info, result));

    }else{
        result = (char*) "-_- Opened database successfully trololo";
    }

    /* Create SQL statement */
    /*
    sql =   "CREATE TABLE COMPANY("  \
            "ID INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "AGE            INT     NOT NULL," \
            "ADDRESS        CHAR(50)," \
            "SALARY         REAL );";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        result =  zErrMsg;
        sqlite3_free(zErrMsg);
    }else{
        result = "Table created successfully";
    }
    */

    //sqlite3_close(db);
    return (env)->NewStringUTF((fp) ? "file is here" : "file didn't open" /*+ sz*/);
    /*
    sqlite3**  db;
    int errorCode = sqlite3_open_v2 ("content://telephony/carriers", db, SQLITE_OPEN_URI | SQLITE_OPEN_READONLY , "" );
    const char *  libver = sqlite3_libversion();
     */
    /*
    Table structure
       _id, name, numeric, mcc, mnc, apn, user,
       server, password, proxy, port, mmsproxy,
       mmsport, mmsc, authtype, type, current,
       protocol, roaming_protocol, carrier_enabled, bearer
    */
    //return (*env)->NewStringUTF(env, errorCode ? (char *)sqlite3_errmsg(*db) : "db was opened");
    //return (*env)->NewStringUTF(env, "db was opened");
}

JNIEXPORT jint JNICALL Java_com_example_hellojni_HelloJni_getInt (JNIEnv *env, jobject onject) {
    return 42;
}
