FROM gcc:12
ARG project
COPY /src/$project /usr/src
WORKDIR /usr/src
RUN g++ main.cpp -o fun
CMD ["./fun"]