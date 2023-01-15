docker build -f ./Dockerfile -t fun  ./ --build-arg project=%1

mkdir output

docker run --name funcpp fun
docker cp funcpp:/usr/src/build/output/. ./output/
docker rm funcpp