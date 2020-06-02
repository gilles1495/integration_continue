FROM gradle
RUN mkdir /home/gradle/_project
WORKDIR /home/gradle/_project
VOLUME _project
COPY ./ /home/gradle/_project

ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt update && apt install php openssl php-common php-curl php-json php-mbstring php-mysql php-xml php-zip gzip -yq --no-install-recommends

RUN gradle publish --no-daemon --info
RUN ls _project/build