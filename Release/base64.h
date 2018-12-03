extern "C" int __declspec(dllexport) Base64decode_len(const char *bufcoded);

extern "C" int __declspec(dllexport) Base64decode(char *bufplain, const char *bufcoded);

extern "C" int __declspec(dllexport) Base64encode_len(int src_len);

extern "C" int __declspec(dllexport) Base64encode(char *encoded, const char *string, int len);


extern "C" __declspec(dllexport) char* base64_encode(const unsigned char *data,
											size_t input_length,
											size_t *output_length);

extern "C" __declspec(dllexport) char* base64_decode(const char *data,
											 size_t input_length,
											 size_t *output_length);