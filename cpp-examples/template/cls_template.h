#include <string>

class CompanyA {
 public:
  void sentCleartext(const std::string& msg);
  void sendEncrypted(const std::string& msg);
};

class CompanyB {
 public:
  void sentCleartext(const std::string& msg);
  void sendEncrypted(const std::string& msg);
};

class MsgInfo {};

template <typename Company>
class MsgSender {
  void sendClear(const MsgInfo& msg) {
    Company c;
    c.sentCleartext(msg);
  }

  void sendEncrypt(const MsgInfo& msg) {
    Company c;
    c.sendEncrypted(msg);
  }
};