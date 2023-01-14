FROM opencv
ARG project
COPY /src/$project /usr/src
WORKDIR /usr/src
RUN g++ *.cpp -o fun -pthread
CMD ["./fun"]
