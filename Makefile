.PHONY: test_mc test_wallis test exercises
%: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -lm

exercises: monte_carlo wallis

test: test_mc test_wallis

test_mc: monte_carlo
	./monte_carlo

test_wallis: wallis
	./wallis
