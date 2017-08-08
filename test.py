import pyice_base

def hello_world(req):
    resp = req.create_response()
    resp.set_body("Hello world!")
    resp.send()

def stream_response(req):
    resp = req.create_response()
    ctx = req.get_context()
    stream = resp.stream(ctx)
    resp.send()
    stream.write_str("Hello world! (stream)")
    stream.close()

server = pyice_base.Server()
server.disable_request_logging()
server.load_bitcode_from_file("test_module", "test_module.bc")
server.route_async("/hello_world", hello_world, [])
server.route_async("/hello_world_stream", stream_response, [])
server.run("127.0.0.1:7821")
