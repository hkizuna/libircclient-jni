public class Driver {
  public static void main(String[] args) {
    IRCClient ircClient = IRCClient.getInstance();
    ircClient.connect("irc.dal.net", 6667, "", "xwang", "xwang", "xwang");
    ircClient.setOnConnectListener(mOnConnectListener);
    ircClient.onConnect();
  }

  static IRCClient.OnConnectListener mOnConnectListener = new IRCClient.OnConnectListener() {
    public void onConnect() {
      System.out.println("onConnect called.");
    }
  };
}
