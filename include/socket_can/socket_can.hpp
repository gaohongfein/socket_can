#ifndef SOCKET_CAN_SOCKET_CAN_HPP
#define SOCKET_CAN_SOCKET_CAN_HPP

#include <cstdint>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

namespace socket_can
{
class SocketCAN
{
 public:

  SocketCAN();

  ~SocketCAN();

  bool is_connected();

  bool write(uint32_t frame_id, uint8_t dlc, uint8_t * data);

  bool read(size_t size, uint8_t * data);

 private:
  void init();

  int socket_;

  bool connected_;
};
}

#endif //SOCKET_CAN_SOCKET_CAN_HPP
