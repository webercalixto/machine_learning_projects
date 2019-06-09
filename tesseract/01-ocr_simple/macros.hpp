#define SAVE_LOG(fmt,...) ({\
		printf(fmt "\n",##__VA_ARGS__);\
		fflush(stdout);\
})
