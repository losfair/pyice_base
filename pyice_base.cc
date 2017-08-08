#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include "ice-cpp/ice.h"

namespace py = pybind11;

PYBIND11_MODULE(pyice_base, this_module) {
    py::class_<ice::Server>(this_module, "Server")
        .def(py::init<>())
        .def("listen", &ice::Server::listen)
        .def("load_bitcode", &ice::Server::load_bitcode)
        .def("add_endpoint", &ice::Server::add_endpoint)
        .def("route_async", &ice::Server::route_async)
        .def("disable_request_logging", &ice::Server::disable_request_logging)
        .def("set_session_cookie_name", &ice::Server::set_session_cookie_name)
        .def("set_session_timeout_ms", &ice::Server::set_session_timeout_ms)
        .def("add_template", &ice::Server::add_template)
        .def("set_max_request_body_size", &ice::Server::set_max_request_body_size)
        .def("set_endpoint_timeout_ms", &ice::Server::set_endpoint_timeout_ms)
        .def("run", &ice::Server::run);
    
    py::class_<ice::Context>(this_module, "Context");

    py::class_<ice::CustomProperties>(this_module, "CustomProperties")
        .def("get", &ice::CustomProperties::get)
        .def("set", &ice::CustomProperties::set);
    
    py::class_<ice::Request>(this_module, "Request")
        .def("create_response", &ice::Request::create_response)
        .def("get_context", &ice::Request::get_context)
        .def("borrow_custom_properties", &ice::Request::borrow_custom_properties)
        .def("get_remote_addr", &ice::Request::get_remote_addr)
        .def("get_method", &ice::Request::get_method)
        .def("get_uri", &ice::Request::get_uri)
        .def("get_session_item", &ice::Request::get_session_item)
        .def("get_stats", &ice::Request::get_stats)
        .def("get_header", &ice::Request::get_header)
        .def("get_cookie", &ice::Request::get_cookie)
        .def("get_body", &ice::Request::get_body)
        .def("get_headers", &ice::Request::get_headers)
        .def("get_cookies", &ice::Request::get_cookies)
        .def("get_session_items", &ice::Request::get_session_items)
        .def("set_session_item", &ice::Request::set_session_item)
        .def("set_custom_stat", &ice::Request::set_custom_stat)
        .def("render_template", &ice::Request::render_template);
    
    py::class_<ice::Response>(this_module, "Response")
        .def("set_body", &ice::Response::set_body_s)
        .def("set_file", &ice::Response::set_file)
        .def("set_status", &ice::Response::set_status)
        .def("add_header", &ice::Response::add_header)
        .def("set_header", &ice::Response::set_header)
        .def("set_cookie", &ice::Response::set_cookie)
        .def("stream", &ice::Response::stream)
        .def("send", &ice::Response::send);
    
    py::class_<ice::ResponseStream>(this_module, "ResponseStream")
        .def("write_bytes", &ice::ResponseStream::write_bytes)
        .def("write_str", &ice::ResponseStream::write_str)
        .def("close", &ice::ResponseStream::close);
}
