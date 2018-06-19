FROM ubuntu:16.04
MAINTAINER firmament-dev@camsas.org
ENV http_proxy http://192.168.0.194:8118
ENV https_proxy http://192.168.0.194:8118

RUN apt-get -y update
RUN apt-get -y install git-core build-essential make && git clone -b max_pod_num_1855 https://github.com/islinwb/firmament.git /firmament
RUN bash -c 'source /firmament/include/pkglist.Ubuntu-16.04 && apt-get -y install ${BASE_PKGS} ${COMPILER_PKGS} ${GOOGLE_PKGS} ${BOOST_PKGS} ${MISC_PKGS} ${HDFS_PKGS} ${PION_PKGS}'
RUN mkdir /var/log/firmament && cd /firmament && make && cd build && make -j12
RUN apt-get clean
ENV http_proxy ""
ENV https_proxy ""
