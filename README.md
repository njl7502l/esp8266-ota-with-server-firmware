# ESP8266-OTA-WITH-SERVER-FIRMWARE

## Usage

1. 書き込みたいプログラムを`pio run`でコンパイル -> `.pio/build/esp_wroom_02/firmware.bin`にファイルができる
2. そのディレクトリで`python3 -m http.server 3000`でローカルサーバ起動
3. アクセスポイントの情報を記述するファイルを作成してこのプログラムをマイコンに書き込む。

- シリアルポートのボーレートはこのプログラムと1のファイルとで合わせておく。
