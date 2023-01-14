docker build -f ./Dockerfile -t fun  ./ --build-arg project=%1

docker run --rm fun
