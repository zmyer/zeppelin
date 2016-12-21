#ifndef ZP_BINLOG_RECEIVE_BGWORKER
#define ZP_BINLOG_RECEIVE_BGWORKER
#include "bg_thread.h"
#include "zp_command.h"

struct ZPBinlogReceiveTask {
  uint32_t partition_id;
  const Cmd* cmd;
  client::CmdRequest request;
  std::string raw;
  std::string from_node;
  ZPBinlogReceiveTask(uint32_t id, const Cmd* c,
      const client::CmdRequest &req, const std::string &r,
      const std::string& from)
    : partition_id(id), cmd(c),
    request(req), raw(r), from_node(from) {}
};

class ZPBinlogReceiveBgWorker {
  public:
    ZPBinlogReceiveBgWorker(int full);
    ~ZPBinlogReceiveBgWorker();
    void AddTask(ZPBinlogReceiveTask *task);
  private:
    pink::BGThread* bg_thread_;
    static void DoBinlogReceiveTask(void* arg);
};


#endif //ZP_BINLOG_REDEIVE_BGWORKER
