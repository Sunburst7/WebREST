/*
 * @Author: HH
 * @Date: 2023-03-31 23:07:31
 * @LastEditTime: 2023-04-11 21:51:36
 * @LastEditors: HH
 * @Description: 定义了一系列回调的类型
 * @FilePath: /WebREST/WebREST/core/callback.h
 */

#ifndef WebREST_CALLBACK_H_
#define WebREST_CALLBACK_H_

#include <functional>
#include <memory>
#include "inet_address.h"
#include "buffer.h"

using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

namespace WebREST {

// 前向声明
class TcpConnection;
using TcpConnectionPtr = std::shared_ptr<TcpConnection> ;

using EventCallback = std::function<void()>; // 最基础的事件回调
using ConnectionCallback = std::function<void (const TcpConnectionPtr&)>;           // 连接建立成功的事件回调
using CloseCallback = std::function<void (const TcpConnectionPtr&)>;                // 关闭连接的事件回调
using MessageCallback = std::function<void (const TcpConnectionPtr&, Buffer*)>;     // TCP连接读事件回调

} // namespace WebREST

#endif