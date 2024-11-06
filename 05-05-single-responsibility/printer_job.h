#include <string>

class PrinterJob {
public:
    enum class Kind {
        Print,
        Scan,
        Fax
    };

    enum class Quality {
        Draft,
        Normal,
        Super
    };

    enum class Mode {
        BW,
        Grayscale,
        Color
    };

    enum class InkType {
        Cyan = 0,
        Magenta,
        Yellow,
        Black
    };

    enum class Area {
        A4,
        A5,
        A6,
        Legal,
        Letter
    };

    PrinterJob(PrinterJob::Kind kind);

    // Job origin

    void set_network_source(const std::string ip) {}
    void set_usb_source() {}

    // Print-related API

    void set_print_quality(PrinterJob::Quality quality) {}
    void set_print_resolution(unsigned dpi) {}
    void set_print_mode(PrinterJob::Mode mode) {}

    float get_ink_level(PrinterJob::InkType ink) { return m_ink_level[ink]; }

    bool ready() { return m_ink_level[Cyan] > 0.1 && m_ink_level[Magenta] > 0.1 && m_ink_level[Yellow] > 0.1 && m_ink_level[Black] > 0.1; }

    void set_print_pages(unsigned pages) {}
    void set_print_data(unsigned page, const char * buffer) {}

    // Scanner-related API

    void set_scan_resolution(unsigned dpi) {}
    void set_scan_compression(float quality) {}
    void set_scan_area(PrinterJob::Area area) {}
    const char * scan_page();

    // Fax API

    void set_fax_number(const char * number) {}
    bool dial_number() { return false; }
    void set_fax_gamma(float gamma) {}
    void set_fax_data(const char * buffer) {}
    void send_fax_data();

protected:
    float m_ink_level[4];
};
