n_need,n_brand = map(int, input().split())
bundle_cost = 1001
each_cost = 1001

for i in range(n_brand):
    bundle, each = map(int, input().split())
    bundle_cost = min(bundle_cost, bundle)
    each_cost  = min(each_cost, each)

result = [n_need//6 * bundle_cost + n_need % 6 * each_cost, (n_need//6 + 1) * bundle_cost, n_need * each_cost]
print(min(result))