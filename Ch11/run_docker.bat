docker build -t fun ./ --build-arg project=%1

docker run fun
