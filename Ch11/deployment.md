# Deployment on NVIDIA Jetson

Using `helloworld` and an example:

## Compile executable

```
g++ helloworld/main.cpp -o fun
```

## Create or update executable 

```
mkdir -p /usr/opt/funcpp 

cp fun /usr/opt/funcpp/fun 
```

## Add following command at the end of /etc/systemd/nv.sh 

```
echo ./usr/opt/funcpp/fun >> ./usr/opt/funcpp/fun.log 
```

### OR use the follow command

```
echo "echo ./usr/opt/funcpp/fun >> ./usr/opt/funcpp/fun.log" >> /etc/systemd/nv.sh
```