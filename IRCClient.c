#include "IRCClient.h"
#include <libircclient.h>
#include <string.h>

irc_session_t *session;
irc_callbacks_t callbacks;

void event_connect(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned int count) {

}

void event_channel(irc_session_t *session, const char *event, const char *origin, const char **params, unsigned int count) {

}

void event_numeric(irc_session_t *session, unsigned int event, const char *origin, const char **params, unsigned int count) {

}

void
Java_IRCClient_initialize(JNIEnv *env, jobject obj) {
  if (!session) {
    memset(&callbacks, 0, sizeof(callbacks));

    callbacks.event_connect = event_connect;
    callbacks.event_channel = event_channel;
    callbacks.event_numeric = event_numeric;
    session = irc_create_session(&callbacks);
  }
}

jint
Java_IRCClient_connect(JNIEnv *env, jobject obj, jstring server, jint port, jstring password, jstring nickname, jstring username, jstring realname) {
  const char *cc_server = "irc.dal.net";
  unsigned short us_port = 6667;
  const char *cc_password = NULL;
  const char *cc_nickname = "xwang";
  const char *cc_username = "xwang";
  const char *cc_realname = "xwang";

  if (irc_connect(session, cc_server, us_port, cc_password, cc_nickname, cc_username, cc_realname)) {
    return irc_errno(session);
  }
  if (irc_run(session)) {
    return irc_errno(session);
  }
  return 0;
}

jint
Java_IRCClient_disconnect(JNIEnv *env, jobject obj) {
  if (session) {
    irc_destroy_session(session);
    free(session);
  }
  return 0;
}
