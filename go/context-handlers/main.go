// https://getgophish.com/blog/post/2018-12-02-building-web-servers-in-go/
// https://www.alexedwards.net/blog/making-and-using-middleware
// https://blog.cloudflare.com/the-complete-guide-to-golang-net-http-timeouts/
// https://www.sohamkamani.com/blog/golang/2018-06-17-golang-using-context-cancellation/

// https://github.com/jordan-wright/http-boilerplate/blob/master/server/server.go
package main

import (
	"context"
	"fmt"
	"log"
	"net/http"
	"time"
)

func authMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		ctx, cancel := context.WithTimeout(context.Background(), time.Second*5)
		defer cancel()

		time.Sleep(time.Second * 2)
		log.Println("auth'd")

		next.ServeHTTP(w, r.WithContext(ctx))
	})
}

func main() {
	h := http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		ctx, cancel := context.WithCancel(r.Context())
		defer cancel()

		msg := make(chan string, 1)
		go func() {
			time.Sleep(time.Second * 3)
			msg <- "Hey"
		}()

		select {
		case out := <-msg:
			fmt.Fprintf(w, "%s\n", out)
		case <-ctx.Done():
			http.Error(w, http.StatusText(http.StatusRequestTimeout), http.StatusRequestTimeout)
			cancel()
		}
	})

	http.Handle("/", authMiddleware(h))

	http.ListenAndServe(":8081", nil)
}
