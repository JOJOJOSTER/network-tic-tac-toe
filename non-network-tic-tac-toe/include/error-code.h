#pragma once

#include <string>

class ErrorCode {
public:
  ErrorCode(const std::string &reason) : m_reason(reason) {}

  const std::string &what() const { return m_reason; }
  bool isOk() const { return m_isOk; }

private:
  std::string m_reason;
  bool m_isOk;
};
