#include <node_api.h>

napi_value MyFunction(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 1;
  int number = 0;
  napi_value argv[1];
  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Failed to parse arguments");
  }

  status = napi_get_value_int32(env, argv[0], &number);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Invalid number was passed as argument");
  }
  napi_value myNumber;
  number = number * 2;
  status = napi_create_number(env, number, &myNumber);

  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to create return value");
  }

  return myNumber;
}

void Init(napi_env env, napi_value exports, napi_value module, void *priv) {
  napi_property_descriptor descs[] = {
      {"my_function", 0, MyFunction, 0, 0, 0, napi_default, 0}
  };
  napi_status status = napi_define_properties(env, exports, 1, descs);
}

NAPI_MODULE(addon, Init)