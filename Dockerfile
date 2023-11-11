FROM gcc:13.2
COPY . /AVS/LR02
WORKDIR /AVS/LR02
RUN g++ -o LR02 FileReader.cpp
CMD ["./LR02", "in", "in2", "in3"]