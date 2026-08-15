#ifndef NOTIFICATION_INOTIFIER_HPP
#define NOTIFICATION_INOTIFIER_HPP

#include <string>

namespace notification
{

class INotifier
{
public:
  virtual ~INotifier () = default;

  // 发送通知
  virtual void send (const std::string &receiver,
                     const std::string &message) const = 0;

  // 返回通知类型
  virtual std::string name () const = 0;
};

} // namespace notification

#endif
