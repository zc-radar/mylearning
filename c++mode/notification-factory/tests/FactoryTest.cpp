#include <cassert>
#include <iostream>
#include <stdexcept>

#include "NotifierFactory.hpp"

int main() {
  {
    auto notifier = notification::NotifierFactory::createNotifier("email");

    assert(notifier != nullptr);
    assert(notifier->name() == "email");
  }

  {
    auto notifier = notification::NotifierFactory::createNotifier("sms");

    assert(notifier != nullptr);
    assert(notifier->name() == "sms");
  }

  {
    auto notifier = notification::NotifierFactory::createNotifier("console");

    assert(notifier != nullptr);
    assert(notifier->name() == "console");
  }

  {
    bool exceptionThrown = false;

    try {
      notification::NotifierFactory::createNotifier("unknown");
    } catch (const std::invalid_argument&) {
      exceptionThrown = true;
    }

    assert(exceptionThrown);
  }

  std::cout << "All tests passed.\n";

  return 0;
}
