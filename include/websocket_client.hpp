#pragma once
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <boost/beast/ssl.hpp>
#include <functional>
#include <string>
#include <memory>

namespace net = boost::asio;
namespace ssl = boost::asio::ssl;
namespace beast = boost::beast;
namespace websocket = beast::websocket;
using tcp = net::ip::tcp;

class BinanceWebSocketClient : std::enable_shared_from_this<BinanceWebSocketClient>{
    public:
    using MessageCallback = std::function<void(const std::string&)>; 
    
    BinanceWebSocketClient(net::io_context&, ssl::context&);

    void run(std::string host, std::string port, std::string target);
    void set_on_message(MessageCallback cb);

    private:
    tcp::resolver resolver_;
    websocket::stream<beast::ssl_stream<beast::tcp_stream>> websocket_;
    beast::flat_buffer buffer_;
    MessageCallback message_callback_;
    std::string host_;
    std::string port_;
    std::string target_;
    void on_resolve(beast::error_code ec, tcp::resolver::results_type results);
    void on_connect(beast::error_code ec, tcp::resolver::results_type::endpoint_type ep);
    void on_ssl_handshake(beast::error_code ec);
    void on_handshake(beast::error_code ec);
    void on_read(beast::error_code ec, std::size_t bytes_transferred);
    

};


