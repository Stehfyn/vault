














































































































































































































































































































































































































































 break;
        }
    }

    if (videoStreamIndex == -1) {
        std::cout << "Failed to find video stream in the file" << std::endl;
        avformat_close_input(&formatContext);
        return false;
    }

    AVCodecContext* codecContext = avcodec_alloc_context3(nullptr);
    if (!codecContext) {
        std::cout << "Failed to allocate codec context" << std::endl;
        avformat_close_input(&formatContext);
        return false;
    }

    if (avcodec_parameters_to_context(codecContext, formatContext->streams[videoStreamIndex]->codecpar) < 0) {
        std::cout << "Failed to copy codec parameters to codec context" << std::endl;
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return false;
    }

    AVCodec* codec = avcodec_find_decoder(codecContext->codec_id);
    if (!codec) {
        std::cout << "Failed to find decoder for the codec" << std::endl;
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return false;
    }

    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        std::cout << "Failed to open codec" << std::endl;
        avcodec_free_context(&codecContext);
        avformat_close_input(&formatContext);
        return false;
    }

    AVFrame* frame = av_frame_alloc();
    AVPacket packet;
    av_init_packet(&packet);

    while (av_read_frame(formatContext, &packet) >= 0) {
        if (packet.stream_index == videoStreamIndex) {
            if (avcodec_send_packet(codecContext, &packet) < 0) {
                std::cout << "Failed to send packet to the decoder" << std::endl;
                av_packet_unref(&packet);
                av_frame_free(&frame);
                avcodec_free_context(&codecContext);
                avformat_close_input(&formatContext);
                return false;
            }

            while (avcodec_receive_frame(codecContext, frame) >= 0) {
                if (frame->format == AV_PIX_FMT_RGBA) {
                    width = frame->width;
                    height = frame->height;
                    channels = 4;
                    *imageData = new unsigned char[width * height * channels];
                    memcpy(*imageData, frame->data[0], width * height * channels);
                    break;
                }
            }
        }
        av_packet_unref(&packet);
    }

    av_frame_free(&frame);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);
    return true;
}
```
