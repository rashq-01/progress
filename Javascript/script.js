// LZW Compression Algorithm
function compress(uncompressed) {
    const dictionary = {};
    const data = (uncompressed + "").split("");
    const result = [];
    let dictSize = 256;

    for (let i = 0; i < 256; i++) {
        dictionary[String.fromCharCode(i)] = i;
    }

    let w = "";
    for (let i = 0; i < data.length; i++) {
        const c = data[i];
        const wc = w + c;
        if (dictionary.hasOwnProperty(wc)) {
            w = wc;
        } else {
            result.push(dictionary[w]);
            dictionary[wc] = dictSize++;
            w = c;
        }
    }

    if (w !== "") {
        result.push(dictionary[w]);
    }

    return result;
}

// LZW Decompression Algorithm
function decompress(compressed) {
    const dictionary = [];
    const result = [];
    let dictSize = 256;
    let w = String.fromCharCode(compressed[0]);
    result.push(w);

    for (let i = 0; i < 256; i++) {
        dictionary[i] = String.fromCharCode(i);
    }

    for (let i = 1; i < compressed.length; i++) {
        let entry;
        const k = compressed[i];
        if (dictionary[k]) {
            entry = dictionary[k];
        } else if (k === dictSize) {
            entry = w + w.charAt(0);
        } else {
            throw "Decompression error";
        }

        result.push(entry);

        dictionary[dictSize++] = w + entry.charAt(0);

        w = entry;
    }

    return result.join("");
}

// DOM Elements
const inputText = document.getElementById('inputText');
const outputCompressedText = document.getElementById('outputCompressedText');
const inputCompressedText = document.getElementById('inputCompressedText');
const outputDecompressedText = document.getElementById('outputDecompressedText');

// Compress Button Event
document.getElementById('compressBtn').addEventListener('click', function() {
    const text = inputText.value;
    const compressed = compress(text);
    outputCompressedText.value = compressed.join(',');
});

// Decompress Button Event
document.getElementById('decompressBtn').addEventListener('click', function() {
    const compressedText = inputCompressedText.value.split(',').map(Number);
    const decompressed = decompress(compressedText);
    outputDecompressedText.value = decompressed;
});
