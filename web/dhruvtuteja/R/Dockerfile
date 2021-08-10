FROM ubuntu
RUN apt-get clean \
    && apt-get -y update

RUN apt-get -y install nginx \
    && apt-get -y install build-essential
WORKDIR /usr/src/app
COPY . .
COPY nginx.conf /etc/nginx
COPY index.html /var/www/html/
RUN chmod +x ./start.sh
CMD [ "./start.sh"]
