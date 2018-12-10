extern "C" __declspec(dllexport) int Base64decode_len(const char *bufcoded);

extern "C" __declspec(dllexport) int Base64decode(char *bufplain, const char *bufcoded);

extern "C" __declspec(dllexport) int Base64encode_len(int src_len);

extern "C" __declspec(dllexport) int Base64encode(char *encoded, const char *string, int len);