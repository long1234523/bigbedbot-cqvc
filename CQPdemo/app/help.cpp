#include "help.h"
#include <sstream>
#include <algorithm>
namespace help
{
    const std::vector<std::string> changelog{
        {R"(20190830
����changelog
�����¼���������
�����¼������в���
�¼����������ô���Ϊ5
�¼���������ճ������Ḳ������Ч��
fix: δע����˿���ҡ��
)"},
    };

    std::string boot_info()
    {
        std::stringstream ss;
        ss << "bot���ˣ�";
        ss << help(1);
        return ss.str();
    }

    std::string help(unsigned count)
    {
        std::stringstream ss;
        ss << "���������ڣ�" << __TIMESTAMP__ << std::endl;
        ss << "�޸ļ�¼��" << std::endl;
        for (unsigned i = 0; i < count && i < changelog.size(); ++i)
        {
            ss << changelog[i];
        }
        std::string ret = ss.str();
        while (ret.back() == '\n' || ret.back() == 'r')
        {
            while (ret.back() == '\n') ret.pop_back();
            while (ret.back() == '\r') ret.pop_back();
        }
        return ret;
    }
}
