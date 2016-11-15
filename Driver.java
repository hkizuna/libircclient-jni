import xwang.cordova.irc.IRCClient;

public class Driver {
  public static void main(String[] args) {
    IRCClient ircClient = IRCClient.getInstance();
    ircClient.setOnConnectListener(new IRCClient.OnConnectListener() {
      public void onConnect() {
        ircClient.join("#hkizuna"); 
      }
    });
    ircClient.setOnChannelListener(new IRCClient.OnChannelListener() {
      public void onChannel(String fromPerson, String toChannel, String message) {
        ircClient.message(toChannel, "replied to " + message);
        if (message.equals("quit")) {
          ircClient.disconnect();
        }
      }
    });
    Thread ircThread = new Thread() {
      public void run() {
        ircClient.connect("irc.uuke.co", 6667, "", "hkizuna", "hkizuna", "hkizuna");
      }
    }; 
    ircThread.start();
  }
}
