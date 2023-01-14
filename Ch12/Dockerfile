FROM opencv
ARG project
COPY /src/$project /usr/src
COPY /asset /usr/asset
WORKDIR /usr/src
RUN mkdir build
WORKDIR /usr/src/build
RUN cmake ..
RUN make
CMD ["./fun"]
