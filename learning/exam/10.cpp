struct Athlete {
    int id;
    int height;
    int weight;
};

std::vector<int> sortstudent(const std::vector<int> &height, const std::vector<int> &weight) {
    int num = height.size();  // 获取运动员的数量
    std::vector<Athlete> athletes(num);

    // 填充 athletes 向量
    for (int i = 0; i < num; ++i) {
        athletes[i].id = i + 1;  // 运动员编号从 1 开始
        athletes[i].height = height[i];
        athletes[i].weight = weight[i];
    }

    // 按照身高、体重和编号进行排序
    std::sort(athletes.begin(), athletes.end(), [](const Athlete &a, const Athlete &b) {
        if (a.height != b.height) {
            return a.height < b.height;
        } else if (a.weight != b.weight) {
            return a.weight < b.weight;
        } else {
            return a.id < b.id;
        }
    });

    // 提取并返回排序后的编号
    std::vector<int> sortedIds;
    for (const Athlete &athlete : athletes) {
        sortedIds.push_back(athlete.id);
    }

    return sortedIds;
}