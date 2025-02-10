class TextEditor {
 private:
  const int GAP_SIZE = 1 << 10;
  const int SUBSTR_LEN = 10;
  unique_ptr<char[]> buffer;
  int gapLeft = 0;                        
  int gapRight = gapLeft + GAP_SIZE - 1;  
  int length = GAP_SIZE;
  void grow() {
    int newLength = length * 2;
    auto newBuffer = make_unique<char[]>(newLength);
    memcpy(newBuffer.get(), buffer.get(), gapLeft);
    int chunkSize = length - gapRight - 1;
    int newGapRight = newLength - chunkSize - 1;
    memcpy(newBuffer.get() + newGapRight + 1, buffer.get() + gapRight + 1,
           chunkSize);
    gapRight = newGapRight;

    length = newLength;
    buffer.swap(newBuffer);
  }
 public:
  TextEditor() { buffer = make_unique<char[]>(length); }
  void addText(string_view text) {
    int gapSize = gapRight - gapLeft + 1;
    if (gapSize < text.size()) {
      grow();
    }
    memcpy(buffer.get() + gapLeft, text.data(), text.size());
    gapLeft += text.size();
  }
  int deleteText(int k) {
    int deleted = min(gapLeft, k);
    gapLeft -= deleted;
    return deleted;
  }
  string cursorLeft(int k) {
    for (int i = 0; i < k && gapLeft > 0; i++) {
      buffer[gapRight] = buffer[gapLeft - 1];
      gapLeft--;
      gapRight--;
    }
    int len = min(gapLeft, SUBSTR_LEN);
    return string(buffer.get() + gapLeft - len, len);
  }
  string cursorRight(int k) {
    for (int i = 0; i < k && gapRight < length - 1; i++) {
      buffer[gapLeft] = buffer[gapRight + 1];
      gapLeft++;
      gapRight++;
    }
    int len = min(gapLeft, SUBSTR_LEN);
    return string(buffer.get() + gapLeft - len, len);
  }
};
